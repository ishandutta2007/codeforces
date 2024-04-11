#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int t, cnt;
string s;
vector <int> kq;

bool Check2(int dau, int dai) {
    for(int i = dau; i < 12; i += dai)
        if(s[i] == 'O')
            return 0;
    return 1;
}

void Check(int l) {
    for(int i = 0; i < 12 / l; i++)
    if(Check2(i, 12 / l)) {
        cnt++;
        kq.push_back(l);
        return ;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> t;
    while(t--) {
        cnt = 0;
        cin >> s;
        kq.clear();
        for(int i = 1; i <= 12; i++)
            if(12 % i == 0)
                Check(i);
        cout << cnt << " ";
        for(int i = 0; i < (int)kq.size(); i++)
            cout << kq[i] << "x" << 12 / kq[i] << " ";
        cout << endl;
    }
    return 0;
}