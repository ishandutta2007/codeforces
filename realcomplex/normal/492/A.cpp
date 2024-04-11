#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int l;
    cin >> l;
    int levels = 0;
    int m = 1;
    int s = 2;
    while(l>0){
        if(m <= l){
            levels++;
        }
        l-=m;
        m+=s;
        s++;
    }
    cout << levels;
    return 0;
}