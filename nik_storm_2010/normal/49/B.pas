uses math;
var
    c,d:array[1..5] of longint; answer,numa,numb,cif,a,b:longint;


procedure findanswer;
var per,i:longint;
begin
  cif:=cif+1; per:=0;
  for i:=1 to max(numa,numb) do
    begin
      per:=(per+c[i]+d[i]) div cif;
    end;
  if per<>0 then answer:=max(numa,numb)+1 else answer:=max(numa,numb);
end;


begin

  readln(a,b); cif:=0;
  numa:=0;
  while a>0 do
    begin
      inc(numa); c[numa]:=a mod 10;
      a:=a div 10; cif:=max(cif,c[numa]);
    end;
  numb:=0;
  while b>0 do
    begin
      inc(numb); d[numb]:=b mod 10;
      b:=b div 10; cif:=max(cif,d[numb]);
    end;
  findanswer; writeln(answer);

end.