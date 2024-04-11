#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define INFI 9e18
using namespace std;
int charToInt(char c){
    if (c>='a'&&c<='z') return c-'a';
    else if(c>='A'&&c<='Z')  return c-'A'+'z'-'a'+1;
    return -1;
}
int main(){
    int n,len=('z'-'a'+1)*2,ans,mi,ma,minI,maxI;
    bool end=false;
    string s;
    cin >> n >>s;
    n=s.length();
    ans=n;
    vector<vi > cnt (len);
    vi index (len,0);
    for(int i=0;i<n;i++){
        cnt[charToInt(s.at(i))].pb(i);
    }
    while(!end){
        mi=n; minI=-1;
        ma=0; maxI=-1;
        for(int i=0;i<len;i++){
            if (cnt[i].size()==0) continue;
            if (index[i]>=cnt[i].size()){
                //cout<<"end: "<<i<<endl;
                end=true;
                break;
            }
            //cout<<cnt[i][index[i]]<<endl;
            if(cnt[i][index[i]]>ma){
                maxI=i;ma=cnt[i][index[i]];
            }
            if(cnt[i][index[i]]<mi){
                minI=i;mi=cnt[i][index[i]];
            }
        }
        if (end) break;
        index[minI]++;
        //cout<<ans<<"->";
        ans=min(ans,(ma-mi+1));
        //cout <<minI<<"-"<<maxI<<"-"<<mi<<"-"<<ma<<": "<<ans<<endl;
    }
    cout <<ans<<endl;
}