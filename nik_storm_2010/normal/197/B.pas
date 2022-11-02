var
  a,b:array[0..100] of longint; n,m,x,i:longint;


function gcd(a,b:longint):longint;
begin
  while (a>0) and (b>0) do if a>b then a:=a mod b else b:=b mod a;
  gcd:=a+b;
end;


begin

  readln(n,m);
  for i:=0 to n do read(a[i]);
  for i:=0 to m do read(b[i]);
  if n<m then write('0/1') else
  begin
    if a[0]*b[0]<0 then write('-');
    if n>m then write('Infinity') else
    begin
      x:=gcd(abs(a[0]),abs(b[0]));
      write(abs(a[0]) div x,'/',abs(b[0]) div x);
    end;
  end;

end.