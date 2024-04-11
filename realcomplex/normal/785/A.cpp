#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    string form;
    for(int x = 0;x<n;x++){
        cin >> form;
        if(form[0] == 'T'){
            sum += 4;
        }
        else if(form[0] == 'C'){
            sum += 6;
        }
        else if(form[0] == 'O'){
            sum += 8;
        }
        else if(form[0] == 'D'){
            sum += 12;
        }
        else{
            sum += 20;
        }
    }
    cout << sum;
    return 0;
}