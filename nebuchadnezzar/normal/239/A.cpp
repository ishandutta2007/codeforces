#include <iostream>
#include <vector>

using namespace std;

int y, k, n, x;
vector <int > mas;

int main()
{
    cin >> y >> k >> n;

    for(int i = k - y % k; i + y <= n; i += k)
    {
        mas.push_back(i);    
    }
    if(mas.size() == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        for(int i = 0; i < mas.size(); ++i)
        {
            cout << mas[i] << " ";
        }
        cout << endl;
    }

    return 0;
}