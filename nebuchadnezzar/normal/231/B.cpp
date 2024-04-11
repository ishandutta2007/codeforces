#include <iostream>
#include <cmath>

using namespace std;


int n, d, l, mas[100];

int main()
{
    cin >> n >> d >> l;
    if((n + 1) / 2 * l - n / 2 < d or (n + 1) / 2 - n / 2 * l > d)
    {
        cout << -1;
        return 0;
    }

    int i, bal = 0, next_num, new_num;
    for(i = 0; i < n; ++i)
    {
        if(i % 2 == 0)
        {
            next_num = d - bal;
            next_num = max(next_num, 1);
            next_num = min(l, next_num);
        }            
        else
        {
            next_num = bal - d;
            next_num = max(next_num, 1);
            next_num = min(next_num, l);
            next_num = -next_num;
        }
        bal += next_num;
        mas[i] = abs(next_num);
    }
    bal = bal - d;
    //cout << bal << endl;
    if(bal != 0)
    {
        for(i = 0; i < n; ++i)
        {
            new_num = 0;
            if(bal == 0)
            {
                break;
            }
            if(i % 2 == 0 and bal < 0)
            {
                new_num = min(l - mas[i], int(abs(bal)));
                mas[i] += new_num;
            }            
            else if(i % 2 == 1 and bal > 0)
            { 
                new_num = min(bal, l - mas[i]);
                mas[i] += new_num;
                new_num = -new_num;
            }
            bal += new_num;
            
        }
    }

    for(i = 0; i < n; ++i)
    {
        cout << mas[i] << " ";
    }
    return 0;
}