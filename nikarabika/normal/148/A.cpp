#include <iostream>

using namespace std;

bool A[5001];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return a*b/gcd(a, b);
}

int main()
{
    int k, l, m, n, d;
    cin>>k>>l>>m>>n>>d;
    int kl=lcm(k, l), km=lcm(k, m), kn=lcm(k, n), lm=lcm(l, m), ln=lcm(l, n), mn=lcm(m, n);
    int c=0;
    c+=d/k+d/l+d/m+d/n;
    c-=d/kl+d/km+d/kn+d/lm+d/ln+d/mn;
    c+=d/lcm(kl, m) + d/lcm(kl, n) + d/lcm(km, n) + d/lcm(lm, n) - d/lcm(kl, mn);
    cout<<c<<endl;

    return 0;
}