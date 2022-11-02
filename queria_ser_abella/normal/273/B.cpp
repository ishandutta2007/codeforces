#include <bits/stdc++.h>
#define maxn 200200
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int last[maxn];

int main() {
    
    int n;
    scanf("%d",&n);
    vector<pii> v;
    for(int i=0;i<2*n;i++){
        int a;
        scanf("%d",&a);
        v.pb(pii(a,i%n));
    }
    int mod;
    scanf("%d",&mod);
    sort(v.begin(),v.end());
    ll ans = 1;
    for(int i=0;i<2*n;i++){
        if(i && v[i-1].first == v[i].first)
            continue;
        int qt = 0, rep = 0;
        for(int j=i;j<2*n && v[j].first == v[i].first;j++){
            qt++;
            if(last[v[j].second] == i+1)
                rep++;
            last[v[j].second] = i+1;
        }
        for(int j=1;j<=qt;j++){
            int aux = j;
            while(rep > 0 && aux%2 == 0)
                aux /= 2, rep--;
            ans *= aux;
            ans %= mod;
        }
    }
    printf("%lld\n",ans);
}