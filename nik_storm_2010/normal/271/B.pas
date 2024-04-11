uses math;
var
    mas:array[1..100000] of longint; ver,gor:array[1..500] of longint;
      used:array[1..100003] of boolean; answer,leng,nom,n,m,i,j,c,x:longint;


procedure sieve;
var max,i,j:int64;
begin
  max:=100003; i:=2; leng:=0;
  while i<=max do
    begin
      if used[i]=false then
      begin
        inc(leng); mas[leng]:=i; j:=i*i;
        while j<=max do
          begin
            used[j]:=true;
            j:=j+i;
          end;
      end; inc(i);
    end;
end;


procedure find(c:longint; var nom:longint);
var l,m,r:longint;
begin
  l:=1; r:=leng;
  while r-l>1 do
    begin
       m:=(r+l) div 2;
      if mas[m]>c then r:=m else l:=m;
    end;
  if c<=mas[l] then nom:=l else nom:=r;
end;


begin

  readln(n,m); sieve;
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(c); find(c,nom); x:=mas[nom]-c;
          ver[j]:=ver[j]+x; gor[i]:=gor[i]+x;
        end;
      readln;
    end;
  answer:=maxlongint;
  for i:=1 to n do answer:=min(answer,gor[i]);
  for j:=1 to m do answer:=min(answer,ver[j]);
  writeln(answer);

end.