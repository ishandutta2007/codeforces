#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define rep(i,n)    for(int i = 0;i < n;i++)

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<long long> ary(n);
    rep(i,n)
    {
        cin >> ary[i];
    }
    long long offset = 0;
    rep(i,m)
    {
        int cmd;
        cin >> cmd;
        switch(cmd)
        {
            case 1:
            long long p,x;
            cin >> p >> x;
            ary[p-1] = x - offset;
            break;
            case 2:
            long long o;
            cin >> o;
            offset += o;
            break;
            case 3:
            long long q;
            cin >> q;
            cout << ary[q-1]+offset << endl;
            break;
        }
    }
    return 0;
}