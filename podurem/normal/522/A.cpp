#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>




struct rb{
    std::string from, to;
};

std::vector <rb> mas;

long k = 2;
long maxx = 0;

void dfs(int s, int n){
    for(int i = s; i < n; i++){
        if((mas[s].to == mas[i].from) && (i != s)){
            k+= 1;
            //std::cout << i << ' ' << k << std::endl;
            dfs(i, n);
            k--;

        }
        else{
            maxx = std::max(maxx, k);
            //std::cout <<maxx<<std::endl;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    mas.resize(n);

    for(int i = 0; i < n; i++){
        std::string to, r, from;
        std::cin >> to >> r >> from;
        std::transform(to.begin(), to.end(), to.begin(), tolower);
        std::transform(from.begin(), from.end(), from.begin(), tolower);
        mas[i].from = from;
        mas[i].to = to;
    }
   // for(int i = 0; i < n; i++)
     //   std:: cout << mas[i].from << '-' << mas[i].to << std::endl;
    for(int i = 0; i < n; i++)
        dfs(i, n);
    std::cout << maxx;
    return 0;
}