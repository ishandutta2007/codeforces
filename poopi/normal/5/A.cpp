                            /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

string str;
int main(){
    int sum = 0, cnt = 0;
    while(getline(cin, str)){
        if(str[0] == '+')
            cnt++;
        else if(str[0] == '-')
            cnt--;
        else{
            int p = 0;
            while(str[p++] != ':');
            sum += (str.length() - p) * cnt;
        }
    }
    cout << sum << endl;
    return 0;
}