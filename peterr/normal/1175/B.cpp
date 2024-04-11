#include <bits/stdc++.h>

using namespace std;

int L;

int main()
{
    cin >> L;
    vector<int> st;
    vector<long long> count;
    count.push_back(1);
    long long sum = 0;
    bool overflow = false;
    while (L--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "add")
        {
            if (count[count.size() - 1] == -1)
                overflow = true;
            else
                sum += count[count.size() - 1];
            if (sum > ((long long) 1 << 32) - 1)
                overflow = true;
        }
        else if (cmd == "for")
        {
            int n;
            cin >> n;
            st.push_back(n);
            long long next = n * count[count.size() - 1];
            if (count[count.size() - 1] == -1 || next > ((long long) 1 << 32) - 1)
            {
                count.push_back(-1);
            }
            else
            {
                count.push_back(next);
            }
        }
        else
        {
            st.pop_back();
            count.pop_back();
        }
    }

    if (overflow)
        cout << "OVERFLOW!!!";
    else
        cout << sum;
    return 0;
}