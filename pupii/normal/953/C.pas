var
a:array[0..100000]of longint;
n,i,T:longint;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    i:=0;
    while ((i<n) and (a[i+1]=a[1])) do inc(i);
    T:=i;
    if( ( n mod T )<>0 )then begin
        writeln('NO');
        exit;
    end;
    for i:=1 to n do begin
        if( a[i] <> (((i-1)div T) and 1 ) xor a[1] )then begin
            writeln('NO');
            exit;
        end;
    end;
    writeln('YES');
end.