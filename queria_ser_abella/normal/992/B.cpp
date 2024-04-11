#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
#define ll long long
using namespace std;

int main() {
    int l,r,x,y;
    scanf("%d%d%d%d",&l,&r,&x,&y);
    vector<int> d;
    for(int i=1;i*i<=y;i++){
        if(y%i == 0){
            d.pb(i);
            if(i*i != y)
                d.pb(y/i);
        }
    }
    int ans = 0;
    for(int i=0;i<d.size();i++)
        for(int j=0;j<d.size();j++){
            if(d[i] < l || d[i] > r || d[j] < l || d[j] > r) continue;
            if(__gcd(d[i],d[j]) != x) continue;
            if( ((ll)d[i]*d[j]) / __gcd(d[i],d[j]) != y) continue;
            ans++;
        }
    printf("%d\n",ans);
}