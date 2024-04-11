type
    Tmas=array[1..407,1..407] of char;
    
var
    a,b:Tmas;
    i,j,h,w:longint;
    
BEGIN
readln(w,h);
for i:=1 to h do
    begin
        for j:=1 to w do
            read(a[i,j]);
        readln;
    end;
for i:=1 to w do
    for j:=1 to h do
        b[i,j]:=a[h-j+1,i];
for i:=1 to w do
    for j:=1 to h do
        a[i,j]:=b[i,h-j+1];
for i:=1 to w do
    for j:=1 to h do
        begin
            b[2*i-1,2*j-1]:=a[i,j];
            b[2*i,2*j-1]:=a[i,j];
            b[2*i,2*j]:=a[i,j];
            b[2*i-1,2*j]:=a[i,j];
        end;
for i:=1 to 2*w do
    begin
        for j:=1 to 2*h do
            write(b[i,j]);
        writeln;
    end;
END.