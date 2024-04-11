#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;
    string test;
    int now,before;
    before = 0;
    test = n;
    now = 0;
    for(int x = 0;x<test.size() - 1;x++){
        if(test[x] == 'V' && test[x + 1] == 'K'){
            now++;
        }
    }
    if(now > before){
        before = now;
    }
    for(int i = 0;i<n.size();i++){
        test = n;
        now = 0;
        if(test[i] == 'V'){
            test[i] = 'K';
        }
        else{
            test[i] = 'V';
        }
        for(int x = 0;x<test.size() - 1;x++){
            if(test[x] == 'V' && test[x + 1] == 'K'){
                now++;
            }
        }
        if(now > before){
            before = now;
        }
    }
    cout << before;
    return 0;
}