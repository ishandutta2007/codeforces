                                /* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int arr[4];

int main(){
    int ptr = 0;
    for(int i = 1; i <= 4; i++)
            cin >> arr[i];
 //  int p = 1;
    while(arr[1] > 1 || arr[2] > 1 || arr[3] > 1 || arr[4] > 1){
                 bool chang = false;
                 for(int i = 1; i <= 4; i++){
                         int j = i % 4 + 1;
                         if((arr[i] & 1) == 0 && (arr[j] & 1) == 0){
                                    cout << "/" << i << endl;
                                    arr[i] /= 2;
                                    arr[j] /= 2;
                                    chang = true;
                                    break;           
                         }
                         else if((arr[i] > 1 || arr[j] > 1) && (arr[i] & 1) == 1 && (arr[j] & 1) == 1){
                                    cout << "+" << i << endl;
                                    cout << "/" << i << endl;
                                    arr[i] = (arr[i] + 1) / 2;
                                    arr[j] = (arr[j] + 1) / 2;
                                    chang = true;
                                    break;           
                         }
                 }             
                 if(chang) continue;
                 for(int i = 1; i <= 4; i++){
//                         p = p % 4 + 1;
                         if(arr[i] == 1) continue;
                         int j = i % 4 + 1;
                         cout << "+" << i << endl;
                         arr[i]++;
                         arr[j]++;
                         chang = true;
                         break;
                 } 
    }
    //cin >> p;
return 0;
}