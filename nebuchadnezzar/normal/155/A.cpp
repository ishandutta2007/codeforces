#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    int i, num, minn, maxn, ans = 0;
    cin >> minn;
    maxn = minn; 
    for(i = 1; i < N; ++i)
    {
        cin >> num;
        //cout << num << " " << minn;
        if(num > maxn)
        {
            ++ans;
            maxn = num;
            //cout << "max";
        }
        if(num < minn)
        {
            ++ans;
            minn = num;
            //cout << "min";
        }
        //cout << endl;        
    }
    cout << ans;
    return 0;
}