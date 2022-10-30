program storm;
var d,i,j,k,max:longint;
    s,s1,s2:string;


procedure inputdata;
begin
 readln(s);
end;

procedure outputdata;
begin
 writeln(max);
end;

begin
 inputdata;
 d:=length(s); max:=0;
 for k:=d-1 downto 1 do
  for i:=1 to d-k+1 do
   for j:=i+1 to d-k+1 do
    begin
    s1:=copy(s,i,k); s2:=copy(s,j,k);
    if s1=s2 then begin max:=k; outputdata; halt; end;
    end;
 outputdata;
end.