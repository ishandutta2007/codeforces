#include <iostream>
#include <cmath>

using namespace std;

int gcd(int m, int n)
{
    
    if(n == 0)
    {   
        
        return m;
    }
    return gcd(n, m % n);
}

int s1, s2, s3, i;

int main()
{
    cin >> s1 >> s2 >> s3;
    
    int a, b, c;
    int gcd_s1_s2 = gcd(s1, s2);
    b = sqrt((s1 / gcd_s1_s2) * s3 / (s2 / gcd_s1_s2));
    a = s1 / b;
    c = s3 / b;
    cout << (a + b + c) * 4;
    return 0;
}