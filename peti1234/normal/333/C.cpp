#include <bits/stdc++.h>

using namespace std;
int k, m;
vector<int> ans;
void pb(int a) {
    ans.push_back(a), ans.push_back(-a);
}
vector<int> kul(vector<int> ans) {
    vector<int> ans2;
    sort(ans.begin(), ans.end());
    for (int x:ans) {
        if (ans2.size()==0 || x!=ans2.back()) {
            ans2.push_back(x);
        }
    }
    return ans2;
}
vector<int> valt(int a, int b, bool s) {
    ans.clear();
    vector<int> ans2;
    pb(a+b), pb(a-b), pb(a*b);
    if (s) {
        pb(10*a+b);
    }
    return kul(ans);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> m;
    for (int a=0; a<10; a++) {
        for (int b=0; b<10; b++) {
            for (int c=0; c<10; c++) {
                for (int d=0; d<10; d++) {
                    vector<int> s1=valt(a, b, 1), s2=valt(c, d, 1), s3, ossz;
                    for (int x:s1) {
                        for (int y:s2) {
                            s3=valt(x, y, 0);
                            for (int z:s3) {
                                ossz.push_back(z);
                            }
                        }
                    }
                    ossz=kul(ossz);
                    for (int x:ossz) {
                        int ert=k-x;
                        if (ert>=0 && ert<10000) {
                            m--;
                            cout << a << b << c << d;
                            if (ert<1000) {
                                cout << 0;
                                if (ert<100) {
                                    cout << 0;
                                    if (ert<10) {
                                        cout << 0;
                                    }
                                }
                            }
                            cout << ert << "\n";
                            if (m==0) {
                                return 0;
                            }

                        }
                    }
                }
            }
        }
    }
    return 0;
}