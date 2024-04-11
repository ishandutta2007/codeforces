#include <bits/stdc++.h>

using namespace std;
const int c=400002;
int n, par[c], sum;
bool ol[c], v[c], baj;
vector<int> bal, jobb;
void solve(int kezd, int veg) {
    //cout << "solve " << kezd << " " << veg << "\n";
    int elkis=kezd-1, kis=kezd, elnagy=2*n+2-kezd, nagy=elnagy;
    int cnt=0, ans=0;
    int kdb=0;
    //cout << elkis << " " << kis << " " << elnagy << " " << nagy << "\n";
    //return;
    while (kdb<veg-kezd+1) {
        if (cnt%2==0) {
            // kis ertekek kellenek a tetejere
            // elnagy=nagy
            for (int i=elkis+1; i<=kis; i++) {
                if (!v[i]) {
                    kdb++;
                    if (ol[i]) {
                        ans++;
                    }
                    v[i]=1, v[par[i]]=1;
                    bal.push_back(i), jobb.push_back(par[i]);
                    nagy=min(nagy, par[i]);
                    //cout << "kislap " << i << " " << par[i] << "\n";
                }
            }
            elkis=kis;
        } else {
            for (int i=elnagy-1; i>=nagy; i--) {
                if (!v[i]) {
                    kdb++;
                    if (ol[i]) {
                        ans++;
                    }
                    v[i]=1, v[par[i]]=1;
                    bal.push_back(i), jobb.push_back(par[i]);
                    kis=max(kis, par[i]);
                    //cout << "nagylap " << i << " " << par[i] << "\n";
                }
            }
            elnagy=nagy;
        }
        cnt++;
    }
    sum+=min(ans, veg-kezd+1-ans);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        par[a]=b, par[b]=a;
        ol[b]=1;
    }
    int kezd=1, mini=c;
    for (int i=1; i<=n; i++) {
        mini=min(mini, par[i]);
        if (i+mini==2*n+1) {
            solve(kezd, i);
            kezd=i+1, mini=c;
        }
    }
    if (kezd!=n+1) {
        baj=1;
    }
    sort(bal.begin(), bal.end());
    sort(jobb.rbegin(), jobb.rend());
    for (int i=0; i<bal.size(); i++) {
        if (par[bal[i]]!=jobb[i]) {
            baj=1;
        }
    }
    if (baj) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n";
    }
    return 0;
}