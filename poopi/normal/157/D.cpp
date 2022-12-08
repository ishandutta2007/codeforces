                                        /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n, m;
int arr[100010];
int x, y;
int pos[100010];
int neg[100010];
bool can[100010];
int res[100010];
string out[3] = {"Truth", "Not defined", "Lie"};

int main(){
    while(cin >> n >> m){
        x = 0, y = 0;
        memset(pos, 0, sizeof pos);
        memset(neg, 0, sizeof neg);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(arr[i] > 0){
                pos[arr[i]]++;
                x++;
            }
            else{
                neg[-arr[i]]++;
                y++;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            int tmp = pos[i] + y - neg[i];
            can[i] = (tmp == m);
            if(can[i])
                cnt++;
        }
        for(int i = 0; i < n; i++){
            if(cnt == 1){
                if(arr[i] > 0)
                    res[i] = (can[arr[i]] ? 0 : 2);
                else res[i] = (can[-arr[i]] ? 2 : 0);
            }
            else{
                if(arr[i] > 0)
                    res[i] = (can[arr[i]] ? 1 : 2);
                else res[i] = (can[-arr[i]] ? 1 : 0);
            }
            cout << out[res[i]] << endl;
        }
    }
    return 0;
}