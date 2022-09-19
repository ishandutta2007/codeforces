#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
ld px, py, vx, vy, a, b, c, d;
pair<ld, ld> st, uj;
pair<ld, ld> lep(pair<ld, ld> st, ld ix, ld iy, ld tav) {
    ld dif=sqrt(tav*tav/(ix*ix+iy*iy));
    if (tav<0) {
        st.first-=ix*dif;
        st.second-=iy*dif;
    }
    else {
        st.first+=ix*dif;
        st.second+=iy*dif;
    }
    cout << st.first << " " << st.second << "\n";
    return st;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.precision(20);
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    st.first=px, st.second=py;
    lep(st, vx, vy, b);
    uj=lep(st, -vy, vx, a/2);
    uj=lep(uj, vy, -vx, (a-c)/2);
    uj=lep(uj, vx, vy, -d);
    uj=lep(uj, vy, -vx, c);
    uj=lep(uj, vx, vy, d);
    uj=lep(uj, vy, -vx, (a-c)/2);
    return 0;
}
/*
10 10 7 0 5 8 2 11
*/