#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ret(int x){
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(x == 2) return 5;
    if(x == 5) return 2;
    if(x == 8) return 8;

    return -1;
}

bool correct(int h, int m, int nh, int nm){
    int ph = 0, pm = 0;
    if(ret(nh/10) == -1) return false;
    if(ret(nh%10) == -1) return false;
    if(ret(nm/10) == -1) return false;
    if(ret(nm%10) == -1) return false;

    pm = 10 * ret(nh%10) + ret(nh/10);
    ph = 10 * ret(nm%10) + ret(nm/10);

    if(ph < h && pm < m) return true;
    return false;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int h, m; scanf("%d %d", &h, &m);
        int nh, nm; scanf("%d:%d", &nh, &nm);

        for(int i=1;i<=10000;i++){
            if(correct(h, m, nh, nm)){
                if(nh < 10) printf("0");
                printf("%d:", nh);
                if(nm < 10) printf("0");
                printf("%d\n", nm);
                break;
            }
            nm++;
            if(nm >= m) { nm -= m; nh += 1; }
            nh %= h;
        }
    }
}