#include <bits/stdc++.h>
using namespace std;

int main(){

    int interval, d, h, mid;
    char c;
    string s;

    while(1){
        cin >> s;
        interval = -1;
        if (s == "start"){
            for(int i = 0; i<30; i++){
                cout << '?' << " " << (1 << (i + 1)) << " " << (1 << i) << endl;
                fflush(stdout);
                cin >> c;
                if(c == 'y'){
                    interval = i;
                    break;
                }
                else if(c == 'e'){
                        return 0;
                }
            }


            if (interval == -1){
                cout << '!' << " " << 1 << endl;
                fflush(stdout);
            }

            else{
                d = (1 << interval) + 1;
                h = 1 << (interval + 1);

                for(int i = 0; i<30; i++){
                    mid = (d + h) / 2;
                    cout << '?' << " " << (1 << (interval + 1)) + 1 << " " << mid << endl;
                    fflush(stdout);
                    cin >> c;
                    if(c == 'y'){
                        d = (mid + 1);
                    }

                    else if(c == 'e'){
                        return 0;
                    }

                    else{
                        h = mid;
                    }
                }

                cout << '!' << " " << mid << endl;
                fflush(stdout);
            }
        }

        else if(s == "mistake") return 0;
        else return 0;
    }

}