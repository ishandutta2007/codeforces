#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

#define Inf 1000000
#define int64 long long
#define Max 1000000

int main(){
    string Str, tmp;
    cin>>Str;
    tmp = Str;
    for (int i = 0; i < Str.length(); i++)
        if(Str[i] >= '5')Str[i] = '0' + ('9' - Str[i]);
    if(Str[0] == '0')
        Str[0] = '9';
    for (int j = 0; j < Str.length(); j++) {
        cout<<Str[j];
    }
    cout<<endl;
    return 0;
}