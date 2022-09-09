#include <iostream>
#include <cmath>

using namespace std;

long long n;
int i;

int s(int x)
{
    int ans;
    while(x > 0)
    {
        ans += x % 10;
        x /= 10;
    }
    return  ans;
}

int main()
{
    cin >> n;
    int sn = int(sqrt(n)) + 1;
    for(i = max(1, sn - 170); i < sn; ++i)
    {
        if(n % i == 0)
        {
            //cout << i << endl;
            if(i + s(i) == n / i)
            {
                cout << i;
                return 0;
            }
        }
    }
    cout << "-1";
    return 0;

}