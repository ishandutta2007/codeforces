# include <fstream>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    char inp[10];
    int i;
    
    fin>>inp>>i;
    
    if(inp[0]=='f'&&i==1)
        fout<<"L\n";
    else if(inp[0]=='f'&&i==2)
        fout<<"R\n";
    else if(inp[0]=='b'&&i==1)
        fout<<"R\n";
    else if(inp[0]=='b'&&i==2)
        fout<<"L\n";
    return 0; 
}