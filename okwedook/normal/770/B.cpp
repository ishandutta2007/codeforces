#include <iostream>
#include <cmath>

using namespace std;

int get_len(unsigned long long n)
{
    int k = 0;
    while(n != 0)
    {
        k++;
        n /= 10;
    }
    return k;
}

int get_first(unsigned long long n)
{
    int k;
    while(n != 0)
    {
        k = n % 10;
        n /= 10;
    }
    return k;
}

unsigned long long get_previos(unsigned long long n)
{
    unsigned long long k = get_first(n) - 1;
    for(int i = 1; i < get_len(n); i++)
    {
        k = k * 10 + 9;
    }
    return k;
}

unsigned long long get_result(unsigned long long n, unsigned long long res, int eight_pos)
{
    unsigned long long temp = get_first(n);
    for(int i = 1; i < get_len(n); i++)
    {            
        if(i == eight_pos)
        {
            temp = temp * 10 + 8;
        }
        else
        {
            temp = temp * 10 + 9;
        }           
    }
    if(n >= temp && eight_pos <= get_len(n))
    {
        res = get_result(n,temp,eight_pos + 1);
    }
    return res;
}

int main()
{
    unsigned long long n;
    cin>>n;
    cout<<max(get_previos(n),get_result(n,0,1));
    return 0;
}