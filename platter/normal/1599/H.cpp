#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int Max = 1e9;
const int Min = 1;

int ask(int i, int j)
{
    if(i > Max || i < Min || j > Max || j < Min) return -1;
    cout << "? " << i << " " << j << endl;
    int ret; cin >> ret;
    if(ret == -1) return 0;
    return ret;
}

void answer(int p, int q, int x, int y)
{
    cout << "! " << p << " " << q << " " << x << " " << y << endl;
    exit(0);
}

int fi(int x, int y)
{
    int ri = ask(x, Max);
    int le = ask(x, Min);
    int up = ask(Max, y);
    int dow = ask(Min, y);

    answer(Min+dow-1, Min+le-1, Max-up+1, Max-ri+1);
}

int main()
{
    int A = ask(1, 1);
    int B = ask(1, Max);
    int r = 0;
    if(A%2 == B%2) r = (Max + A - B)/2;
    else r = (Max + A - B + 1)/2;

    int H = ask(1, r);

    int l = 1;
    while(l < r)
    {
        int mid = (l + r)/2;
        int k = ask(H, mid);
        if(k > 2) l = mid + 1;
        else if(k == 2) fi(H, mid);
        else r = mid - 1;
    }
    fi(H, l);
}