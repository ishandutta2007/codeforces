                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int n, k;
vector <int> pr;
bool npr[1010];

void find_prime(){
    for(int i = 2; i < 1000; i++){
        if(!npr[i]){
            pr.push_back(i);
            for(int j = 2 * i; j < 1000; j += i)
                npr[j] = true;
        }
    }
}

int main(){
    find_prime();
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0; i < pr.size() && pr[i] <= n; i++)
        for(int j = 0; pr[j] < pr[i]; j++)
            if(pr[j] + pr[j+1] + 1 == pr[i])
                cnt++;
    cout << (cnt < k ? "NO" : "YES") << endl;
    return 0;
}