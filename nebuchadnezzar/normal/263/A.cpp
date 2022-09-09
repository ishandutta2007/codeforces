#include <cstdio>
#include <iostream>
#include <cmath>


using namespace std;

int num;


int main()
{
    for(int i = 1; i <= 5; ++i)
    {
        for(int j = 1; j <= 5; ++j)
        {
            cin >> num;
            if(num == 1)
            {
                cout << fabs(3 - i) + fabs(3 - j);
                return 0;
            }
        }
    }


    return 0;
}