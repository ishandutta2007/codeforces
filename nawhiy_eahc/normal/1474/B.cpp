#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
bool p[30000];

void getPrime(){
    fill(p, p + 30000, true);
    for(int i=2;i<30000;i++){
        if(p[i]){
            for(int j=i*i;j<30000;j+=i){
                p[j] = false;
            }
            prime.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    getPrime();
    while(t--){
        int n;
        cin >> n;
        int p1, p2, id1, id2;
        id1 = lower_bound(prime.begin(), prime.end(), 1 + n) - prime.begin();
        p1 = prime[id1];
        id2 = lower_bound(prime.begin(), prime.end(), p1 + n) - prime.begin();
        p2 = prime[id2];

        cout << p1 * p2 << "\n";
    }
}