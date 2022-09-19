#include <bits/stdc++.h>

using namespace std;
int w, n, ert[100005];
vector<int> crm, imp;
bool v[15];
bool test=0;
bool ask(int a, int b, int c) {
    cout.flush() << "? " <<  a << " " << b << " " << c << endl;
    if (test) {
        int ert=v[a]+v[b]+v[c];
        //cout << "valasz " << (ert<=1) << endl;
        return (ert<=1);
    }
    bool x;
    cin >> x;
    return x;
}
void solve(int c) {
    int a=crm[0], b=imp[0];
    if (a==c || b==c) {
        return;
    }
    bool x=ask(a, b, c);
    if (x==0) imp.push_back(c);
    else crm.push_back(c);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        if (test) {
            for (int i=1; i<=n; i++) v[i]=0;
            int x;
            cin >> x;
            for (int i=1; i<=x; i++) {
                int p;
                cin >> p;
                v[p]=1;
            }
        }
        int cm=0, ip=0;
        for (int i=1; i<=n; i+=3) {
            ert[i]=ask(i, i+1, i+2);
            if (ert[i]) cm=i;
            else ip=i;
        }
        //cout << "alap " << cm << " " << ip << "\n";
        int fixc=0, fixi=0;
        if (!ask(cm, cm+1, ip)) {
            fixc=cm+2, fixi=ip;
        } else if (!ask(cm, ip, ip+1)) {
            fixc=cm+1, fixi=ip+1;
        } else {
            fixc=cm, fixi=ip+2;
        }
        //cout << "ertek " << fixc << " " << fixi << endl;
        crm.push_back(fixc), imp.push_back(fixi);
        for (int i=0; i<3; i++) {
            solve(cm+i);
            solve(ip+i);
        }
        //cout.flush() << "kezd " << crm[0] << " " << imp[0] << "\n" << "\n" << "\n" << "\n";

        for (int i=1; i<=n; i+=3) {
            if (i==cm || i==ip) continue;
            if (ert[i]==1) {
                if (ask(i, i+1, imp[0])) {
                    crm.push_back(i);
                    crm.push_back(i+1);
                    solve(i+2);
                } else {
                    crm.push_back(i+2);
                    bool x=ask(crm[0], imp[0], i);
                    int jo=i, rossz=i+1;
                    if (!x) swap(jo, rossz);
                    crm.push_back(jo);
                    imp.push_back(rossz);
                }
            } else {
                if (!ask(i, i+1, crm[0])) {
                    imp.push_back(i);
                    imp.push_back(i+1);
                    solve(i+2);
                } else {
                    imp.push_back(i+2);
                    bool x=ask(crm[0], imp[0], i);
                    int jo=i, rossz=i+1;
                    if (!x) swap(jo, rossz);
                    crm.push_back(jo);
                    imp.push_back(rossz);
                }
            }
        }
        sort(imp.begin(), imp.end());
        cout << "! " << imp.size() << " ";
        for (auto x:imp) {
            cout << x << " ";
        }
        cout.flush() << endl;
        crm.clear(), imp.clear();



    }
    return 0;
}
/*
1
12
6
2 3 6 7 9 12
*/