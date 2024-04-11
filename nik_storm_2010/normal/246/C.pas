var
    a:array[1..50] of longint; leng,nom,n,k,i:longint;


procedure bubblesort;
var tmp,i,j:longint;
begin
  for i:=1 to n do
    for j:=i+1 to n do
    if a[i]>a[j] then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
    end;
end;


begin

  readln(n,k); for i:=1 to n do read(a[i]); bubblesort;
  leng:=1; nom:=n;
  while k<>0 do
    begin
      write(leng,' '); write(a[nom],' '); dec(k);
      for i:=n-leng+2 to n do write(a[i],' ');
      if nom<>1 then dec(nom) else
        begin
          inc(leng); nom:=n-leng+1;
        end;
      writeln;
    end;

end.