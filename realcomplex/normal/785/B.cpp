#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mazsk = 2000000000;
    int lielsk = 0;
    int sk1,sk2;
    for(int x = 0;x<n;x++){
        cin >> sk1 >> sk2;
        if(sk2 < mazsk){
            mazsk = sk2;
        }
        if(sk1 > lielsk){
            lielsk = sk1;
        }
    }
    int lielPeriods = 0;
    cin >> n;
    for(int x = 0;x<n;x++){
        cin >> sk1 >> sk2;
        if(sk1 - mazsk > lielPeriods){
            lielPeriods = sk1 - mazsk;
        }
        if(lielsk - sk2 > lielPeriods){
            lielPeriods = lielsk - sk2;
        }

    }
    cout << lielPeriods;
    return 0;
}