#include <bits/stdc++.h>

using namespace std;
int sum;
int el;
int n;
int t[102];
bool c=false;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        t[i]=a;
        if (i!=1) {
            if (el==1) {
                if (a==1) {
                    c=true;
                }
                if (a==2) {
                    sum+=3;
                }
                if (a==3) {
                    sum+=4;
                }
            }
            if (el==2) {
                if (a==1) {
                    sum+=3;
                } else {
                    c=true;
                }
            }
            if (el==3) {
                if (a==1) {
                    sum+=4;
                } else {
                    c=true;
                }
            }
        }
        el=a;
    }
    for (int i=1; i<=n; i++) {
        if (t[i]==1 && t[i-1]==3 && t[i+1]==2) {
            sum--;
        }
    }
    if (c) {
        cout << "Infinite";
    } else {
        cout << "Finite" << endl << sum << endl;
    }
    return 0;
}