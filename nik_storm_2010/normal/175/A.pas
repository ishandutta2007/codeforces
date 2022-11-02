var
    c1,c2,c3,d,i,j,ans:longint;
     s,s1,s2,s3:string;



procedure prov(s:string; var tek:longint);
var i,code:longint;
 begin
  i:=length(s);
   if ((s[1]='0') and (i<>1)) or (i>7)
    then
     begin
      tek:=-1;
      exit;
     end;
  val(s,tek,code);
   if tek>1000000
  then tek:=-1;
 end;


begin

  readln(s); ans:=-1;
   d:=length(s);
  if d<3 then begin writeln(-1); halt; end;

  for i:=1 to d-2 do
   for j:=i+1 to d-1 do
    begin
     s1:=copy(s,1,i); prov(s1,c1);
      s2:=copy(s,i+1,j-i); prov(s2,c2);
     s3:=copy(s,j+1,d-j); prov(s3,c3);

     if (c1<>-1) and (c2<>-1) and (c3<>-1) and (c1+c2+c3>ans) then ans:=c1+c2+c3;
    end;
  writeln(ans);

end.