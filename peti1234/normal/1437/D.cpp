#include <bits/stdc++.h>

using namespace std;
int w, n, db, el, x, esz, cnt, usz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> el, db=1, esz=1, cnt=1, usz=0;
        for (int i=1; i<n; i++) {
            cin >> x;
            if (x<el) {
                cnt++;
                if (cnt>esz) {
                    esz=usz, cnt=1, usz=0, db++;
                }
            }
            usz++, el=x;
        }
        cout << db << "\n";
    }
    return 0;
}
/*
1
5
1 5 4 3 2
*/