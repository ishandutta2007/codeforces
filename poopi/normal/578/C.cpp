                                        /* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n;
int arr[200010];

double getWeakness(double x){
    double res = 0;
    for(int sg = -1; sg <= 1; sg += 2){
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += sg * (arr[i] - x);
            if(sum < 0) sum = 0;
            res = max(sum, res);
        }
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    double l = -10000, r = 10000;
    for(int i = 0; i < 100; i++){
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;
        double w1 = getWeakness(m1);
        double w2 = getWeakness(m2);
        if(w1 > w2)
            l = m1;
        else r = m2;
    }
    cout << setprecision(8) << fixed << getWeakness(r) << endl;
    return 0;
}