#include <bits/stdc++.h>

using namespace std;
int n;
int gy=0;
int p=1;
int abc=1;
int maxi=0;
int main()
{
    cin >> n;
    int xy=sqrt(n);
    while(n!=1 && xy*xy==n) {
        gy++;
        n=xy;
        xy=sqrt(n);
    }
    if (n==1) {
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    int y=n;
    for (int i=2; i<=1000000; i++) {
        if (n%i==0) {
            p*=i;
            abc*=i;
        }
        int f=0;
        while(n%i==0) {
            n/=i;
            f++;
        }
        maxi=max(maxi, f);
    }
    int x=1;
    while(x<maxi) {
        x*=2;
        gy++;
    }
    if (maxi==1) {
        gy--;
    }
    cout << abc << " ";
    cout << gy+1 << endl;
    return 0;
}