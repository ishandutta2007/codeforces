var
  ans,a,b,x:longint;

function nod(a,b:longint):longint;
begin
  if (b=0) then exit(a);
  exit(nod(b,a mod b));
end;

procedure print(ans:longint);
begin
  writeln(ans);
  halt;
end;

begin
  readln(a,b);
  if (a=b) then print(0);
  x:=nod(a,b);
  a:=a div x;
  b:=b div x;
  ans:=0;
  while (a mod 2=0) do begin a:=a div 2; inc(ans); end;
  while (a mod 3=0) do begin a:=a div 3; inc(ans); end;
  while (a mod 5=0) do begin a:=a div 5; inc(ans); end;
  while (b mod 2=0) do begin b:=b div 2; inc(ans); end;
  while (b mod 3=0) do begin b:=b div 3; inc(ans); end;
  while (b mod 5=0) do begin b:=b div 5; inc(ans); end;
  if (a<>b) then writeln(-1) else writeln(ans);
end.