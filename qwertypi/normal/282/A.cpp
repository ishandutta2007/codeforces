#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <iomanip>
#include <vector>
#include <ctype.h>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int n;
int main(){
    char arr[3];
    int res = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr;
        if(arr[1] == '+'){
            res++;
        }else if(arr[1] == '-'){
            res--;
        }
    }
    cout << res;
}