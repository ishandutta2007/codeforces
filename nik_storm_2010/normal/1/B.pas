uses math;
const
    a: array[1..26] of char = ('A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z');
var
    n,i,i1,d,code,stolb,cif :longint;
    s,ss,st: string;


function prov(s: string) : boolean;
var i,d:longint;
 begin
  d:=length(s);
   for i:=1 to d do
    if s[i] = 'C' then exit(True);
  exit(False);
 end;


Begin

  readln(n);
   for i:=1 to n do
    begin
     readln(s);
      if (s[1]='R') and (ord(s[2]) < 64) and (prov(s) = true)
       then
        begin

         i1:=1; d:=length(s);
          while s[i1]<>'C' do inc(i1);
           st:=copy(s,2,i1-2);
            ss:=copy(s,i1+1,d-i1);
             val(ss,stolb,code);

         while stolb > 0 do
          begin
           cif:=stolb mod 26;
            if cif=0 then cif:=26;
             st:=a[cif] + st;
              stolb:=(stolb-1) div 26;
          end;

         writeln(st);

        end


       else
        begin

         i1:=1; d:=length(s);
          while (ord(s[i1]) > 64) and (ord(s[i1]) < 91) do inc(i1);
           st:=copy(s,1,i1-1);
            ss:=copy(s,i1,d-i1+1);
             stolb:=0;
              cif:=1;

         while length(st) > 0 do
          begin
           stolb:=stolb+cif*(ord(st[length(st)]) - 64);
            cif:=cif*26;
             delete(st,length(st),1);
          end;

         writeln('R',ss,'C',stolb);

        end;
    end;

End.