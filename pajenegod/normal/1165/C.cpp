#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;
int n;
int mem[300000];
int nex[300000];
int spec[300000];
int jump[300000];


int best(int ind)
{
    if (mem[ind] == 0)
    {   
        int ans = 0;

        if (ind>n)
            ans = n + 100;
        else if (ind == n)
            ans = 0;
        else
        {
            ans = 1 + best(ind + 1);
            nex[ind] = ind + 1;
            
            int i = jump[ind] + 1;
            if (i < n)
            {
                int x = i - (ind + 1) + best(i+1);
                if (x < ans)
                {
                    ans = x;
                    nex[ind] = i+1;
                    spec[ind] = 1;
                }
            }
        }
        mem[ind] = ans + 1;
    }
    return mem[ind] - 1;
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    cin >> S;

    char prev = '2';
    int prev_ind;
    for (int i=n-1; i>=0; --i)
    {
        if (S[i] != prev)
        {
            prev = S[i];
            prev_ind = i;
        }
        jump[i] = prev_ind;
    }

    best(0);
    string out;
    
    for (int ind = 0; ind < n; ind = nex[ind])
    {
        if (spec[ind] == 0) continue;
        out.push_back(S[ind]);
        out.push_back(S[nex[ind]-1]);
    }
    

    cout << best(0) << '\n';
    cout << out;
}