#include<bits/stdc++.h>
using namespace std;
char arr[101][101]={NULL};
char ans[101][102]={NULL};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=0;i<((n<<1)-1);++i){
        for(int j=0;j<((n<<1)-1);++j){
            ans[i][j]='x';
        }
        ans[i][(n<<1)-1]='\n';
    }
    ans[n-1][n-1]='o';
    vector<pair<int,int> > o,dot,x;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(arr[i][j]=='o'){
                o.push_back(make_pair(i,j));
            }
            else if(arr[i][j]=='x'){
                x.push_back(make_pair(i,j));
            }
            else{
                dot.push_back(make_pair(i,j));
            }
        }
    }
    for(vector<pair<int,int> >::iterator it = o.begin();it!=o.end();++it){
        for(vector<pair<int,int> >::iterator it2 = dot.begin();it2!=dot.end();++it2){
            ans[n-1+it2->first -it->first][n-1+it2->second-it->second]='.';
        }
    }
    for(vector<pair<int,int> >::iterator it = x.begin();it!=x.end();++it){
        bool f=0;
        for(vector<pair<int,int> >::iterator it2 = o.begin();it2!=o.end();++it2){
            if(ans[n-1+it->first-it2->first][n-1+it->second-it2->second]=='x'){
                f=1;
                break;
            }
        }
        if(!f){
            printf("NO");
            exit(0);
        }
    }
    printf("YES\n");
    for(int i=0;i<((n<<1)-1);++i){
        cout<<ans[i];
    }
}