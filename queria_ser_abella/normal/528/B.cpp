#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define maxn 300300
#define ll long long
#define debug 
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<pii> v;
    for(int i=0,x,w;i<n;i++){
        scanf("%d%d",&x,&w);
        v.pb(pii(x+w,x-w));
    }
    sort(v.begin(),v.end());
    int ans = 0;
    int pos = -(1e9+1000);
    for(int i=0;i<n;i++){
        if(v[i].second >= pos){
            ans++;
            pos = v[i].first;
        }
    }
    printf("%d\n",ans);
}