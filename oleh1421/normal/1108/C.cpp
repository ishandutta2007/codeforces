#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<char> a[3];
int k(int i,char c){
    int rez=0;
    for (int j=0;j<a[i].size();j++) rez+=(a[i][j]==c);
    return rez;
}
int b[6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++) a[i%3].push_back(s[i]);
    b[0]=a[0].size()-k(0,'R')+a[1].size()-k(1,'G')+a[2].size()-k(2,'B');
    b[1]=a[0].size()-k(0,'R')+a[1].size()-k(1,'B')+a[2].size()-k(2,'G');
    b[2]=a[0].size()-k(0,'G')+a[1].size()-k(1,'R')+a[2].size()-k(2,'B');
    b[3]=a[0].size()-k(0,'G')+a[1].size()-k(1,'B')+a[2].size()-k(2,'R');
    b[4]=a[0].size()-k(0,'B')+a[1].size()-k(1,'R')+a[2].size()-k(2,'G');
    b[5]=a[0].size()-k(0,'B')+a[1].size()-k(1,'G')+a[2].size()-k(2,'R');
    int minx=b[0];
    int index=0;
    for (int i=1;i<6;i++){
        if (minx>b[i]){
            minx=b[i];
            index=i;
        }
    }
    char g[3];
    if (index==0){
       g[0]='R';
       g[1]='G';
       g[2]='B';
    } else if (index==1){
       g[0]='R';
       g[1]='B';
       g[2]='G';
    }else if (index==2){
       g[0]='G';
       g[1]='R';
       g[2]='B';
    }else if (index==3){
       g[0]='G';
       g[1]='B';
       g[2]='R';
    }else if (index==4){
       g[0]='B';
       g[1]='R';
       g[2]='G';
    }else if (index==5){
       g[0]='B';
       g[1]='G';
       g[2]='R';
    }
    cout<<minx<<endl;
    for (int i=0;i<n;i++) cout<<g[i%3];
    return 0;
}