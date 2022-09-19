#include <bits/stdc++.h>

using namespace std;
const int c=2002;
int w, n, kezd[c], veg[c], db[4];
string a, b;
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        n=a.size();
        ans.clear();
        for (int i=0; i<4; i++) {
            db[i]=0;
        }
        for (int i=0; i<n; i++) {
            if (i%2) {
                int x=2*(a[i-1]=='1')+(a[i]=='1');
                db[x]++, kezd[i/2]=x;
                int y=2*(b[i]=='1')+(b[i-1]=='1');
                db[y]--, veg[i/2]=y;
            }
        }
        n/=2;
        if (db[0] || db[3]) {
            cout << -1 << "\n";
            continue;
        }
        int spec=0;
        if (db[1]) {
            int dif=0, dif2=0;
            for (int i=0; i<n; i++) {
                if (kezd[i]==1) {
                    dif++;
                }
                if (kezd[i]==2) {
                    dif--;
                }
                if (veg[i]==1) {
                    dif2--;
                }
                if (veg[i]==2) {
                    dif2++;
                }
                if (dif==db[1]) {
                    ans.push_back(i);
                    for (int j=0; j<=i; j++) {
                        if (kezd[j]%3) {
                            kezd[j]=3-kezd[j];
                        }
                    }
                    reverse(kezd, kezd+i+1);
                    break;
                }
                if (dif2==db[1]) {
                    spec=2*(i+1);
                    for (int j=0; j<=i; j++) {
                        if (veg[j]%3) {
                            veg[j]=3-veg[j];
                        }
                    }
                    reverse(veg, veg+i+1);
                    break;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                if (kezd[j]==veg[n-i-1]) {
                    if (j) {
                        ans.push_back(j-1);
                    }
                    ans.push_back(j);
                    for (int k=j; k>0; k--) {
                        swap(kezd[k], kezd[k-1]);
                    }
                    break;
                }
            }
        }
        if (spec) {
            ans.push_back(spec/2-1);
        }
        cout << ans.size() << "\n";
        for (int x:ans) {
            int s=2*(x+1);
            reverse(a.begin(), a.begin()+s);
            cout << 2*(x+1) << " ";
        }
        cout << "\n";
    }
    return 0;
}