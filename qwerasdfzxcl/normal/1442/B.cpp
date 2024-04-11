#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], b[200200];
int idx[200200], t[200200];
vector<pair<int, int>> dung;

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        dung.clear();
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i=0;i<n;i++){
            idx[i+1]=0;
            t[i]=0;
        }
        for (int i=0;i<n;i++) scanf("%d", a+i);
        for (int i=0;i<k;i++) scanf("%d", b+i);
        for (int i=0;i<n;i++){
            idx[a[i]]=i;
        }
        for (int i=0;i<k;i++){
            t[idx[b[i]]]=i+1;
        }
        int z=0, z2;
        while(z<n){
            if (!t[z]){
                z++;
                continue;
            }
            z2=z;
            while(z2<n && t[z2]) z2++;
            dung.push_back(make_pair(z, z2));
            z=z2;
        }
        ll ans=1, mod=998244353;
        for (auto &p:dung){
            if (ans==0){
                //printf("%d %d\n", p.first, p.second);
                break;
            }
            if (p.first==0){
                for (int i=1;i<p.second;i++){
                    if (t[i-1]<t[i]) ans=0;
                }
                continue;
            }
            if (p.second==n){
                for (int i=p.first+1;i<n;i++){
                    if (t[i-1]>t[i]) ans=0;
                }
                continue;
            }
            vector<pair<int, int>> tmp;
            for (int i=p.first;i<p.second;i++) tmp.push_back(make_pair(t[i], i));
            sort(tmp.begin(), tmp.end());
            for (int j=0;j<(int)tmp.size();j++) t[tmp[j].second]=j+1;
            int x=p.first, y=p.second-1, z=1;
            bool test=1;
            while(x<y){
                if (t[x]!=z && t[y]!=z){
                    test=0;
                    break;
                }
                if (t[x]==z){
                    x++;
                    z++;
                }
                else{
                    y--;
                    z++;
                }
            }
            if (test){
                ans *= 2;
                ans %= mod;
            }
            else ans=0;
        }
        printf("%lld\n", ans);
    }
    return 0;
}