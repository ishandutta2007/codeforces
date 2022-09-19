#include <bits/stdc++.h>

using namespace std;
int w, n, k, po[20], pos;
vector<pair<int, int> > sz;
void valt(int &a) {
    while (a<0) {
        a+=k;
    }
    while (a>=k) {
        a-=k;
    }
}
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> k;
        po[0]=1;
        sz.push_back({0, 1});
        while (po[pos]<n) {
            pos++;
            po[pos]=po[pos-1]*k;
            sz.push_back({0, 1});
        }
        for (int i=0; i<n; i++) {
            int ert=0;
            int ii=i;
            for (int j=0; j<=pos; j++) {
                int fi=sz[j].first, se=sz[j].second;
                int s=(fi+se*(ii%k));
                valt(s);
                //cout << "ertek " << j << " " << s << "\n";
                ert+=po[j]*s;
                ii/=k;
            }
            cout.flush() << ert << "\n";
            int ans;
            cin >> ans;
            if (ans==1) {
                break;
            }
            int ert2=ert;
            for (int j=0; j<=pos; j++) {
                sz[j].first*=-1, sz[j].second*=-1;
                sz[j].first+=ert2%k;
                valt(sz[j].first), valt(sz[j].second);
                ert2/=k;
            }
        }
        sz.clear(), pos=0;
    }
    return 0;
}
/*
1
3 3
*/