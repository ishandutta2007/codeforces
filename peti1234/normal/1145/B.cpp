#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin >> n;
    if (n%10==1 || n%10==9 || n%10==7 || (n>=10 && n<=29 && n!=12) || n>90 || (n>=70 && n<80)) cout << "No";
    else cout << "Yes";
    return 0;
}