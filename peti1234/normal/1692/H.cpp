#include <bits/stdc++.h>

using namespace std;
const int c=200005, gy=500;
int n, kezd, veg, ki, ans, t[200005];
map<int, int> db;
map<int, vector<int> > p;
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            db[t[i]]++;
            p[t[i]].push_back(i);
        }
        for (auto x:db) {
            int ert=x.second, id=x.first;
            if (ert>=gy) {
                int mini=0, pos=0, cnt=0;
                for (int i=1; i<=n; i++) {
                    if (t[i]==id) cnt++;
                    else cnt--;
                    if (cnt<mini) {
                        mini=cnt, pos=i;
                    }
                    if (cnt-mini>ans) {
                        ans=cnt-mini;
                        kezd=pos+1, veg=i, ki=id;
                    }
                }
            } else {
                vector<int> v=p[id];
                for (int i=0; i<ert; i++) {
                    for (int j=i; j<ert; j++) {
                        int a=v[i], b=v[j], dif=2*(j-i+1)-(b-a+1);
                        if (dif>ans) {
                            ans=dif;
                            kezd=a, veg=b, ki=id;
                        }
                    }
                }
            }
        }
        cout << ki << " " << kezd << " " << veg << "\n";

        kezd=veg=ki=ans=0;
        db.clear(), p.clear();
    }

    return 0;
}
/*
1
5
4 4 3 4 4
*/