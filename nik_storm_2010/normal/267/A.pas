var
    sum,a,b,n,i:longint;


procedure evklid(a,b:longint);
begin
  while (a>0) and (b>0) do
    begin
      if a>b then begin sum:=sum+(a div b); a:=a mod b; end
             else begin sum:=sum+(b div a); b:=b mod a; end;
    end;
end;


begin

  readln(n);
  for i:=1 to n do
    begin
      readln(a,b); sum:=0;
      evklid(a,b); writeln(sum);
    end;

end.