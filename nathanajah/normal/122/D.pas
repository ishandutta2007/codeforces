var 
n,k:int64; 
s:ansistring; 
i,j:longint; 
countop:int64; 
 
begin 
readln(n,k); 
readln(s); 
for i:=1 to length(s) do 
begin  
        //writeln('TEST'); 
        if countop>=k then break; 
        if (s[i]='4') and (s[i+1]='7') then 
        begin 
                if i mod 2 =1 then 
                begin 
                        if (s[i+2]='7') then 
                        begin 
                                if (k-countop) mod 2=1 then 
                                        s[i+1]:='4'; 
                                break; 
                        end 
                        else 
                                s[i+1]:='4';             
                end 
                else 
                begin 
                        if (s[i-1]='4') then     
                        begin 
                                if (k-countop) mod 2=1 then      
                                        s[i]:='7'; 
                                break; 
                        end 
                        else 
                                s[i]:='7'; 
                end; 
                inc(countop); 
        //      writeln(s); 
        end; 
end; 
writeln(s); 
end.