#include <bits/stdc++.h>

using namespace std;
int t[1000001];
int id=1, ke, oe, kh, nh, oh, n, maxi;
int el[1000001];
int nagy[1000001];
int kis[1000001];
void ans(int a){ cout << a << " ";}
void jav(int id) {nagy[id-1]=max(0, nagy[id]+t[id-1]), kis[id-1]=min(0, kis[id]+t[id-1]);}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        char c;
        cin >> c;
        int a=t[id];
        if (c=='R') {
            id++, a=t[id];
            oh-=a;
            oe+=a;
            if (oe<0) {
                ke++;
            } else if(!el[oe] && oe) el[oe]=id, maxi++;
        } else if (c=='L' && id!=1) {
            oh+=a, jav(id+1);
            if (oe<0) ke--; else if (oe && el[oe]==id) el[oe]=0, maxi--;
            oe-=a, id--;
        } else if (c!='L'){
            int x;
            if (c=='(') x=1; else if (c==')') x=-1; else x=0;
            int y=x-t[id], uj=oe+y;
            ke-=(oe<0), ke+=(uj<0);
            if (uj>0 && !el[uj]) el[uj]=id, maxi++;
            if (oe>0 && y<0 && el[oe]==id) el[oe]=0, maxi--;
            t[id]=x, oe=uj;
        }
        int kh=kis[id+1], nh=nagy[id+1];
        cout << "\n";
        if (oe+oh!=0 || ke>0 || oe+kh<0) ans(-1);
        else ans(max(maxi, oe+nh));
    }
    return 0;
}