#include <bits/stdc++.h>


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int c,v0,v1,a,l;
    ios::sync_with_stdio(false);
    cin >> c >> v0 >> v1 >> a >> l;
    int x = 0, cnt = 0;
    while(x < c) {
        if(x > 0)
           x -= l;
        x += v0;
        v0 += a;
        if(v0 > v1)
           v0 = v1;
        cnt++;
    }
    cout << cnt;
    //cin.close();
    //cout.close();
    return 0;
}