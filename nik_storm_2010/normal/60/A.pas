program storm;
var
    i,j,n,m,kol:longint;



procedure inputdata;
var i,chiclo,code,j,r,l:longint;
    s,s1:string;
begin
 readln(n,m); kol:=0; l:=1; r:=n;
 for i:=1 to m do
  begin
   readln(s); s1:=copy(s,1,12); j:=length(s);
   while s[j]<>' ' do dec(j); val(copy(s,j+1,length(s)-j),chiclo,code);
   if s1='To the right' then begin if chiclo+1>l then l:=chiclo+1; end
                        else begin if r>chiclo-1 then r:=chiclo-1; end;
  end;
 if l>r then kol:=-1
        else kol:=r-l+1;
end;

procedure outputdata;
begin
 writeln(kol);
end;

begin
 inputdata;
 outputdata;
end.